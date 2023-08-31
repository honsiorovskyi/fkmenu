# fkmenu

This app might be useful when you have a "Auto-hide menu bar" macOS option enabled, and you're bothered AF by the fact that this menu bar pops up every time you move your mouse to switch a tab in your browser.

So the app will just block menu from appearing by not allowing your cursor to reach the top 4 (or whatever you see in the code) pixels of your screen (carefull this might be messing with some graphic apps or games; IDK tho, I didn't test it with any xD).

You can prevent the app from doing it by holding Cmd, Alt or Fn when you're moving the mouse to the top of the screen. Also you can manually show the menu bar with Ctrl+F2 (macOS built-in thing).

## Usage

Very simple:

* Install Xcode
* Clone the repo
* Run:
```
make
sudo make install

fkmenu 
# or even
tmux new -d fkmenu
```

## GUI vs no-GUI

This is a terminal application because I really don't like all those Apple tools to make GUI, and neither I want to learn them. For me just `tmux`ing it is enough. If you want GUI — you're welcome to ~steal this code~ for the repo and do whatever you want with it :)