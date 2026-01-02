#!/bin/bash

# 1. Ask for the problem name for the commit message
echo "Enter Problem Name (e.g., 001_TwoSum):"
read problemName

# 2. Pull latest changes (Important to prevent "Rejected" errors)
git pull origin main

# 3. Add all files (including your new folder and code)
git add .

# 4. Commit and Push
git commit -m "Solved: $problemName | $(date +'%Y-%m-%d')"
git push origin main

echo "Done! Your DSA repo is synced."