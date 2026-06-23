@echo off
setlocal

:: Run from project root (location of this .bat file)
cd /d "%~dp0"

echo.
echo  BioStar Device SDK - Documentation Builder
echo  ============================================
echo.

:: ----------------------------------------------------------------
:: Step 1: Generate combined release_notes.md (newest first)
:: ----------------------------------------------------------------
echo [1/2] Generating release_notes.md ...

set "TMPPS=%TEMP%\bs2sdk_relnotes_%RANDOM%.ps1"

(
echo $refDir = '_reference\ko'
echo $outFile = Join-Path $refDir 'release_notes.md'
echo.
echo # NEW VERSION: Add the new release_note_XXXX.md filename to the TOP of this list
echo $files = @^(
echo     'release_note_2912.md', 'release_note_299.md',  'release_note_298.md',
echo     'release_note_296.md',  'release_note_294.md',  'release_note_291.md',
echo     'release_note_283.md',  'release_note_2829.md', 'release_note_282.md',
echo     'release_note_281.md',  'release_note_280.md',  'release_note_27212.md',
echo     'release_note_272.md',  'release_note_271.md',  'release_note_270.md',
echo     'release_note_2640.md', 'release_note_264.md',  'release_note_26316.md',
echo     'release_note_26312.md','release_note_26311.md','release_note_26310.md',
echo     'release_note_263.md',  'release_note_262.md',  'release_note_261.md',
echo     'release_note_260.md',  'release_note_250.md',  'release_note_240.md',
echo     'release_note_231b.md', 'release_note_230.md',  'release_note_220.md',
echo     'release_note_210.md',  'release_note_200.md'
echo ^)
echo.
echo $sb = [System.Text.StringBuilder]::new^(^)
echo [void]$sb.AppendLine^('# Release Notes'^)
echo [void]$sb.AppendLine^(''^)
echo.
echo foreach ^($f in $files^) {
echo     $path = Join-Path $refDir $f
echo     if ^(Test-Path $path^) {
echo         $c = ^(Get-Content $path -Raw -Encoding UTF8^).TrimEnd^(^)
echo         [void]$sb.AppendLine^($c^)
echo         [void]$sb.AppendLine^(''^)
echo         [void]$sb.AppendLine^('---'^)
echo         [void]$sb.AppendLine^(''^)
echo     } else {
echo         Write-Warning ^('Not found: ' + $f^)
echo     }
echo }
echo.
echo [System.IO.File]::WriteAllText^($outFile, $sb.ToString^(^), [System.Text.UTF8Encoding]::new^($false^)^)
echo Write-Host ^('  Created: ' + $outFile^) -ForegroundColor Green
) > "%TMPPS%"

powershell -NoProfile -ExecutionPolicy Bypass -File "%TMPPS%"
set "PS_RESULT=%errorlevel%"
del "%TMPPS%" 2>nul

if %PS_RESULT% neq 0 (
    echo.
    echo  ERROR: Failed to generate release_notes.md
    pause
    exit /b 1
)

:: ----------------------------------------------------------------
:: Step 2: Run Doxygen (English)
:: ----------------------------------------------------------------
echo.
echo [2/2] Running Doxygen ^(English^) ...
doxygen biostar_device_sdk_en

if %errorlevel% neq 0 (
    echo.
    echo  ERROR: Doxygen build failed.
    pause
    exit /b 1
)

echo.
echo  Done^^!  Output: output\html\index.html
echo.

endlocal
