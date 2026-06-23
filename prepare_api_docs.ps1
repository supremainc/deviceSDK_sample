# prepare_api_docs.ps1
# Inserts '@include{doc} bs2_functionname.md' into each function's Doxygen block in BS_API.h.
# Requires EXAMPLE_PATH = _reference/en in the Doxyfile (already configured).
# Run once from the project root; the change is idempotent (won't add duplicates).

param(
    [string]$HeaderFile = 'Include\BS_API.h',
    [string]$RefDir     = '_reference\en'
)

if (-not (Test-Path $HeaderFile)) {
    Write-Error "Not found: $HeaderFile"
    exit 1
}

$utf8NoBom = [System.Text.UTF8Encoding]::new($false)
$lines = [System.IO.File]::ReadAllLines($HeaderFile, $utf8NoBom)

$result       = [System.Collections.Generic.List[string]]::new()
$addedCount   = 0
$skippedCount = 0

$i = 0
while ($i -lt $lines.Count) {
    $line = $lines[$i]

    # Doxygen block: line that is exactly '/**' (with optional surrounding whitespace)
    if ($line -match '^\s*/\*\*\s*$') {
        $blockLines = [System.Collections.Generic.List[string]]::new()
        $blockLines.Add($line)
        $i++

        # Collect block body until the closing ' */'
        while ($i -lt $lines.Count -and $lines[$i] -notmatch '^\s*\*/\s*$') {
            $blockLines.Add($lines[$i])
            $i++
        }
        $closingLine = $lines[$i]   # ' */'
        $i++

        # Find the next non-blank line (the function declaration)
        $j = $i
        while ($j -lt $lines.Count -and $lines[$j].Trim() -eq '') { $j++ }

        # Extract function name (BS2_Xxx pattern)
        $funcName = $null
        if ($j -lt $lines.Count -and $lines[$j] -match '\bBS2_(\w+)\b') {
            $funcName = 'BS2_' + $Matches[1]
        }

        # Only add if not already present
        $hasInclude = ($blockLines | Where-Object { $_ -match '@include\{doc\}' }).Count -gt 0

        if ($funcName -and -not $hasInclude) {
            $mdName = $funcName.ToLower() + '.md'
            $mdPath = Join-Path $RefDir $mdName
            if (Test-Path $mdPath) {
                $blockLines.Add(' * @include{doc} ' + $mdName)
                $addedCount++
            } else {
                $skippedCount++
            }
        }

        foreach ($bl in $blockLines) { $result.Add($bl) }
        $result.Add($closingLine)

    } else {
        $result.Add($line)
        $i++
    }
}

[System.IO.File]::WriteAllLines($HeaderFile, $result.ToArray(), $utf8NoBom)

Write-Host ''
Write-Host "  @include{doc} added : $addedCount functions"
Write-Host "  No md file found    : $skippedCount functions"
Write-Host "  File written        : $HeaderFile"
Write-Host ''
