#!/bin/sh
# Extract position data from login coords as typically logged
cut -d ' ' -f 12-14 < "$1" | cut -c 2- | rev | cut -c 2- | rev | tr -d ','

