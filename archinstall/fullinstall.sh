#!/usr/bin/env bash
set -e

# system update
sudo pacman -Syu --noconfirm

sudo pacman -S --needed --noconfirm base-devel git curl wget

# check for yay
if ! command -v yay &>/dev/null; then
    git clone https://aur.archlinux.org/yay.git /tmp/yay
    cd /tmp/yay
    makepkg -si --noconfirm
    cd ~
    rm -rf /tmp/yay
fi

# programs from file
sudo pacman -S --needed --noconfirm - < programs.txt

#dwm clone build
git clone https://github.com/dein/dwm.git ~/.local/src/dwm
cd ~/projects/dwm
sudo make clean install

echo "[*] Dotfiles verlinken..."
git clone https://github.com/dein/dotfiles.git ~/dotfiles
ln -sf ~/dotfiles/.bashrc ~/.bashrc
ln -sf ~/dotfiles/.config/nvim ~/.config/nvim
ln -sf ~/dotfiles/.config/dwm ~/.config/dwm

echo "[*] Dienste aktivieren..."
sudo systemctl enable --now NetworkManager
sudo systemctl enable --now pipewire

echo "[*] Fertig!"

