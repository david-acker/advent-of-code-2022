
function Run-Solution() {
    param (
        [String]$InputFileName,
        [String]$InputName
    )

    $BasePath = "../../input/day9"
    $InputFilePath = "${BasePath}/${InputFileName}"

    if (Test-Path $InputFilePath) {
        Write-Output "Results for ${InputName} data:"
        & dotnet run $InputFilePath
    }
    else {
        Write-Output "The ${InputName} file could not be found."
    }
}

Write-Output "Day 9: Rope Bridge"
Write-Output ""

Run-Solution -InputFileName "input_test.txt" -InputName "test input"
Run-Solution -InputFileName "input.txt" -InputName "input"