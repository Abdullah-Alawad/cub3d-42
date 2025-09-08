#!/bin/bash
read -p "Enter a commit: " M
git add .
git commit -m "$M"
git push 