$BaseSolutionPath = "src/day"
$ScriptBaseName = "run"

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

   if (Test-Path -Path $SolutionDirectory) {

        $Script = $Null

        if (Test-Path -Path "${SolutionDirectory}/${ScriptBaseName}.ps1") {
            $Script = "./${ScriptBaseName}.ps1"
        }
        elseif (Test-Path -Path "${SolutionDirectory}/${ScriptBaseName}.sh") {
            $Script = "./${ScriptBaseName}.sh"
        }

        if ($Script -ne $Null) {
            Set-Location $SolutionDirectory

            Run-Solution-With-Timing -SolutionScript { & $Script }

            Set-Location - | Out-Null

            Write-Output $Separator
        }
   }
}

Write-Output $Separator

for ($i; $i -le 25; $i++) {
    Run-Solution-For-Day -DayNumber $i
}