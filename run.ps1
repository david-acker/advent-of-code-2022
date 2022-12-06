$BaseSolutionPath = "src/day"
$ScriptName = "run.sh"

$Separator = "=" * 35

function Run-Solution-With-Timing() {
    param (
        [ScriptBlock]$SolutionScript
    )

    $StartTime = $(Get-Date)
    & $SolutionScript
    $EndTime = $(Get-Date)

    $ElapsedTime = $EndTime - $StartTime
    $TotalTime = "{0:HH:mm:ss.fff}" -f [DateTime]($ElapsedTime.Ticks)

    Write-Output ""
    Write-Output "Elapsed Time: ${TotalTime}"
}

function Run-Solution-For-Day() {
   param (
    [int]$DayNumber
   )

   $SolutionDirectory = "${BaseSolutionPath}${DayNumber}"

   if ((Test-Path -Path $SolutionDirectory) -and (Test-Path -Path "${SolutionDirectory}/${ScriptName}")) {
    Set-Location $SolutionDirectory

    Run-Solution-With-Timing -SolutionScript { & "./${ScriptName}" }

    Set-Location - | Out-Null

    Write-Output $Separator
   }
}

Write-Output $Separator

for ($i; $i -le 25; $i++) {
    Run-Solution-For-Day -DayNumber $i
}