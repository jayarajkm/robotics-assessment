#!/usr/bin/env bash
set -euo pipefail

PACKAGES=(
  build-essential
  cmake
  git
  python3
  python3-pip
  python3-venv
  python3-dev
  gdb
  clang
  clang-format
  pkg-config
  libeigen3-dev
)

if command -v sudo >/dev/null 2>&1 && [ "$(id -u)" -ne 0 ]; then
  SUDO="sudo"
else
  SUDO=""
fi

log() {
  echo "[INFO] $*"
}

success() {
  echo "[SUCCESS] $*"
}

fail() {
  echo "[FAILURE] $*" >&2
  exit 1
}

log "Updating apt package lists..."
if ! $SUDO apt-get update; then
  fail "apt update failed"
fi
success "apt package lists updated"

log "Installing required packages..."
if ! $SUDO apt-get install -y "${PACKAGES[@]}"; then
  fail "package installation failed"
fi
success "Required packages installed"
