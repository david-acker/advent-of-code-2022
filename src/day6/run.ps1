
function Run-Solution() {
    param (
        [String]$InputFileName,
        [String]$InputName
    )

    $BasePath = "../../input/day6"
    $SolutionName = "main"

    $InputFilePath = "${BasePath}/${InputFileName}"

    if (Test-Path $InputFilePath) {
        Write-Output "Results for ${InputName} data:"
        & "./${SolutionName}" $InputFilePath 
    }
    else {
        Write-Output "The ${InputName} file could not be found."
    }
}

Write-Output "Day 6: Tuning Trouble"
Write-Output ""

& make - | Out-Null

if ($LastExitCode -ne 0) {
    Write-Output "An error occurred during compilation."
    exit 1
}

Run-Solution -InputFileName "input_test.txt" -InputName "test input"
Write-Output ""
Run-Solution -InputFileName "input.txt" -InputName "input"