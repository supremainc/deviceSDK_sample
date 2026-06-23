#!/usr/bin/env node
'use strict';

const fs   = require('fs');
const path = require('path');
const { execSync } = require('child_process');

// NEW VERSION: prepend the new release_note_XXXX.md filename to the TOP of this list
const RELEASE_NOTE_FILES = [
    'release_note_2912.md', 'release_note_299.md',  'release_note_298.md',
    'release_note_296.md',  'release_note_294.md',  'release_note_291.md',
    'release_note_283.md',  'release_note_2829.md', 'release_note_282.md',
    'release_note_281.md',  'release_note_280.md',  'release_note_27212.md',
    'release_note_272.md',  'release_note_271.md',  'release_note_270.md',
    'release_note_2640.md', 'release_note_264.md',  'release_note_26316.md',
    'release_note_26312.md','release_note_26311.md','release_note_26310.md',
    'release_note_263.md',  'release_note_262.md',  'release_note_261.md',
    'release_note_260.md',  'release_note_250.md',  'release_note_240.md',
    'release_note_231b.md', 'release_note_230.md',  'release_note_220.md',
    'release_note_210.md',  'release_note_200.md',
];

const ROOT = path.resolve(__dirname);

function step(label) {
    console.log(`\n[${label}]`);
}

function generateReleaseNotes(lang, title) {
    const refDir  = path.join(ROOT, '_reference', lang);
    const outFile = path.join(refDir, 'release_notes.md');
    const parts   = [title + '\n'];

    for (const file of RELEASE_NOTE_FILES) {
        const filePath = path.join(refDir, file);
        if (fs.existsSync(filePath)) {
            parts.push(fs.readFileSync(filePath, 'utf8').trimEnd());
            parts.push('\n\n---\n');
        } else {
            console.warn(`  [warn] Not found: ${file}`);
        }
    }

    fs.writeFileSync(outFile, parts.join('\n'), 'utf8');
    console.log(`  Created: ${path.relative(ROOT, outFile)}`);
}

function ensureDir(dir) {
    fs.mkdirSync(path.join(ROOT, dir), { recursive: true });
}

function runDoxygen(doxyfile) {
    console.log(`  $ doxygen ${doxyfile}`);
    execSync(`doxygen ${doxyfile}`, { cwd: ROOT, stdio: 'inherit' });
}

function writeRootRedirect() {
    const html = '<!doctype html><meta charset="utf-8">'
               + '<meta http-equiv="refresh" content="0;url=en/index.html">'
               + '<a href="en/index.html">English</a>';
    fs.writeFileSync(path.join(ROOT, 'output', 'index.html'), html, 'utf8');
    console.log('  Created: output/index.html (redirect → en/)');
}

// ── main ────────────────────────────────────────────────────────────────────

console.log('\nBioStar Device SDK - Documentation Builder');
console.log('===========================================');

step('1/4  Generating release_notes.md (English)');
generateReleaseNotes('en', '# Release Notes');

step('2/4  Generating release_notes.md (Korean)');
generateReleaseNotes('ko', '# 릴리즈 노트');

step('3/4  Running Doxygen (English)');
runDoxygen('biostar_device_sdk_en');  // Creates output/ via HTML_OUTPUT=output

step('4/4  Running Doxygen (Korean)');
ensureDir('output');  // OUTPUT_DIRECTORY=output must exist before Korean build
ensureDir('output/ko');
runDoxygen('biostar_device_sdk_ko');

console.log('\nDone!');
console.log('  English : output/index.html');
console.log('  Korean  : output/ko/index.html\n');
