#!/usr/bin/env python3
import argparse
import multiprocessing
from openpilot.system.hardware import HARDWARE


def main():
  parser = argparse.ArgumentParser(description='Control power saving mode')
  parser.add_argument('--enable', action='store_true', help='Enable power saving mode')
  parser.add_argument('--disable', action='store_true', help='Disable power saving mode')
  args = parser.parse_args()

  if args.enable and args.disable:
    parser.error("Cannot specify both --enable and --disable")
  elif not (args.enable or args.disable):
    parser.error("Must specify either --enable or --disable")

  HARDWARE.set_power_save(args.enable)

  cpu_count = multiprocessing.cpu_count()
  state = "enabled" if args.enable else "disabled"
  print(f"Power save mode [{state}]")
  print(f"Number of CPU cores available: [{cpu_count}]")


if __name__ == "__main__":
  main()
