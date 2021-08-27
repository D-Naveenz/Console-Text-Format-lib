# Some applications like VSCode run ps scripts on Workspace Directory. But if we use native powershell console,
# the PWD is the same directory which ps scripts stored.
# Import helper.ps1
if ($PWD.Path.Contains("\scripts\Win")) {
    Set-Location ..\
    . $PWD\helper.ps1
    Set-Location .\Win
}
else {
    . $PWD\scripts\helper.ps1
}

function IsGCC64 {
    # Setup the Process startup info 
    $pinfo = New-Object System.Diagnostics.ProcessStartInfo
    $pinfo.FileName = "gcc.exe"
    $pinfo.Arguments = "--version"
    $pinfo.UseShellExecute = $false
    $pinfo.CreateNoWindow = $true
    $pinfo.RedirectStandardOutput = $true
    $pinfo.RedirectStandardError = $true

    # Create a process object using the startup info
    $process = New-Object System.Diagnostics.Process
    $process.StartInfo = $pinfo

    # Start the process
    $process.Start() | Out-Null
    # Wait a while for the process to do something
    Start-Sleep -Seconds 3
    # If the process is still active kill it
    if (!$process.HasExited) {
        $process.Kill();
    }

    # get output from stdout and stderr 
    $stdout = $process.StandardOutput.ReadToEnd() 
    # $stderr = $process.StandardError.ReadToEnd()

    # check output for success information, you may want to check stderr if stdout if empty 
    if ($stdout.Contains("x86_64")) { 
        # mingw-W64 installed 
        return $true
    }
    elseif ($stdout.Contains("i686")) {
        # mingw-W32 installed
        return $false
    }
    else { 
        Write-Error "An Error occured! - Couldn't detect minGW version"
        Write-Error "Please make sure run on windows and minGW installed."
        BuildPause
        # exit with errorlevel 1 to indicate an error 
        exit 1 
    }
}