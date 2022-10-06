# Development container for the SAVRASCA tool
# https://github.com/nikita-veshchikov/savrasca

# Default configs:
# - OS: Arch Linux
# - Package manager: pacman
# - Shell: zsh

FROM archlinux:latest
ENV WORKDIR=/home/vscode

RUN pacman -Sy --noconfirm
RUN pacman -S --needed --noconfirm zsh git sudo gcc automake libtool autoconf texinfo make avr-gcc avr-libc avrdude make python

RUN useradd -m vscode
RUN chsh -s /bin/zsh vscode
RUN passwd -d vscode
RUN printf "vscode ALL=(ALL) ALL" >> /etc/sudoers
WORKDIR ${WORKDIR}
USER vscode

RUN git clone https://aur.archlinux.org/yay.git; cd yay; makepkg -si --noconfirm; cd ${WORKDIR}
RUN git clone https://github.com/nikita-veshchikov/savrasca
RUN cd savrasca/simulavr; autoreconf --install && ./configure
# RUN cd savrasca; ./configure

# [Optional] Uncomment this section to install additional OS packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>


