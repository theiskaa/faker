package main

import (
	"fmt"
	"math/rand"
	"os"
	"os/exec"
	"time"
)

// TODO(1): take apps list from arguments
// TODO(2): take time duration between app switches randomly, but take the max second to wait from arguments

func main() {
	apps := []string{
		"Alacritty",
		"Safari",
		"Discord",
	}

	runCommand(apps)
}

func runCommand(apps []string) {
	open, err := exec.LookPath("open")
	if err != nil {
		fmt.Println("Cannot found 'open' command")
		return
	}

	previous := 0
	for {

		index, app := randomize(apps, previous)
		previous = index

		fmt.Printf("> moving to::%d -> %s\n", index, app)
		editorCmd := &exec.Cmd{
			Path:   open,
			Args:   []string{open, "-a", app},
			Stdin:  os.Stdin,
			Stdout: os.Stdout,
			Stderr: os.Stderr,
		}

		if err := editorCmd.Run(); err != nil {
			fmt.Println(err.Error())
		}

		time.Sleep(10 * time.Second)
	}
}

func randomize(apps []string, current int) (int, string) {
	index := rand.Intn(len(apps) - 1)
	if index != current {
		return index, apps[index]
	}

	if index == len(apps)-1 {
		return index - 1, apps[index-1]
	}

	return index + 1, apps[index+1]
}
