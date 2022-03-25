# Simple Driver

Simple Driver is a Linux Kernel Loadable Module (KLM) aka. device driver (hello_driver.c) that prints
“Hello World!” to the Kernel log (printk).

## Usage

Use lsmod, insmod, rmmod commands to display, install and remove it.

```bash
# displays modules
sudo lsmod

# installs module
sudo insmod hello_driver.c

# removes module
sudo rmmod hello_driver
```
# What2Eat
Some days, people living together try to decide what food to order home or dorm room. To
avoid this confusion, program decides to turn this situation into a democratic What2Eat.c game.

## Usage
Just run it.
```bash
./What2Eat
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Acknowledgment
* This project is part of the course CS350 (Operating Systems) at Ozyegin University by Ismail Ari.

## License
[GPL](https://www.gnu.org/licenses/gpl-3.0.html)