#!/usr/bin/env bash
# Runs the mocked client (out/worlds-mock.jar, built by apply_mock.sh +
# javac) the way the original 2004 client expected to be run: current
# directory on the classpath (matches the real java.class.path=.;lib\
# gammacls.zip seen in a genuine Gamma.Log from an actual install - see
# worlds-chat-project.md sec. 4) so resource bundles (MessagesBundle*.
# properties) and world files (NewWorld.world) that live as plain files in
# the install directory, not inside the jar, can be found.
#
# Usage: DISPLAY=:99 ./run_mock.sh
# Requires a real WorldsPlayer install directory as CWD - normally
# assets/WorldsPlayer/ (the one the user provided). Xvfb (or a real X
# server) must already be running and DISPLAY set, otherwise the client
# dies with java.awt.HeadlessException as soon as it builds real UI.
set -euo pipefail
JAR="$(dirname "$0")/out/worlds-mock.jar"
exec java -cp ".:${JAR}" NET.worlds.console.Gamma "$@"
