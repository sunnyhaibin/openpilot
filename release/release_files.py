#!/usr/bin/env python3
import os
import re
from pathlib import Path

HERE = os.path.abspath(os.path.dirname(__file__))
ROOT = HERE + "/.."

blacklist = [
  ".git/",

  "matlab.*.md",

  # no LFS or submodules in release
  ".lfsconfig",
  ".gitattributes",
  ".git$",
  ".gitmodules",
]

# Sunnypilot blacklist
sunnypilot_blacklist = [
  "system/loggerd/sunnylink_uploader.py",  # Temporarily, until we are ready to roll it out widely
  ".idea/",
  ".run/",
  ".*__pycache__/.*",
  ".*\\.pyc",
  "teleoprtc/*",
  "third_party/snpe/x86_64/*",
  "body/board/canloader.py",
  "body/board/flash_base.sh",
  "body/board/flash_knee.sh",
  "body/board/recover.sh",
  ".*/test/",
  ".*/tests/",
  ".*tinygrad_repo/tinygrad/renderer/",
  "README.md",
  ".*internal/",
  "docs/.*",
  ".sconsign.dblite",
  "release/ci/scons_cache/",
  ".gitlab-ci.yml",
  ".clang-tidy",
  ".dockerignore",
  ".editorconfig",
  ".python-version",
  "SECURITY.md",
  "codecov.yml",
  "conftest.py",
  "poetry.lock",
  ".venv/",
]

# Merge the blacklists
blacklist += sunnypilot_blacklist

# gets you through the blacklist
whitelist: list[str] = [
]

# sunnypilot whitelist
sunnypilot_whitelist = [
  "^README.md",
  ".*selfdrive/test/fuzzy_generation.py",
  ".*selfdrive/test/helpers.py",
  ".*selfdrive/test/__init__.py",
  ".*selfdrive/test/setup_device_ci.sh",
  ".*selfdrive/test/test_time_to_onroad.py",
  ".*selfdrive/test/test_onroad.py",
  ".*system/manager/test/test_manager.py",
  ".*system/manager/test/__init__.py",
  ".*system/qcomgpsd/tests/test_qcomgpsd.py",
  ".*system/updated/casync/tests/test_casync.py",
  ".*system/updated/tests/test_git.py",
  ".*system/updated/tests/test_base.py",
  ".*selfdrive/ui/tests/test_translations.py",
  ".*selfdrive/car/tests/__init__.py",
  ".*selfdrive/car/tests/test_car_interfaces.py",
  ".*selfdrive/navd/tests/test_navd.py",
  ".*selfdrive/navd/tests/test_map_renderer.py",
  ".*selfdrive/boardd/tests/test_boardd_loopback.py",
  ".*INTEGRATION.md",
  ".*HOW-TOS.md",
  ".*CARS.md",
  ".*LIMITATIONS.md",
  ".*CONTRIBUTING.md",
  ".*sunnyhaibin0850_qrcode_paypal.me.png",
  "opendbc/.*.dbc",
]

# Merge the whitelists
whitelist += sunnypilot_whitelist


if __name__ == "__main__":
  for f in Path(ROOT).rglob("**/*"):
    if not (f.is_file() or f.is_symlink()):
      continue

    rf = str(f.relative_to(ROOT))
    blacklisted = any(re.search(p, rf) for p in blacklist)
    whitelisted = any(re.search(p, rf) for p in whitelist)
    if blacklisted and not whitelisted:
      continue

    print(rf)
