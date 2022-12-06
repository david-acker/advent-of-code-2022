$BaseSolutionPath = "src/day"
$ScriptName = "run.sh"

$Separator = "=" * 35

function Run-Solution-For-Day() {
   param (
    [int]$DayNumber
   )

   $SolutionDirectory = "${BaseSolutionPath}${DayNumber}"

   if ((Test-Path -Path $SolutionDirectory) -and (Test-Path -Path "${SolutionDirectory}/${ScriptName}")) {
    Set-Location $SolutionDirectory
    & "./${ScriptName}"
    Set-Location - | Out-Null

    Write-Output $Separator
   }
}

Write-Output $Separator

for ($i; $i -le 25; $i++) {
    Run-Solution-For-Day $i
}