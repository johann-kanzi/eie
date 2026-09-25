## Basics
git init
- initializes current project directory as a repository

git add
- adds file to stage to prepare to commit

git help
- opens documentation on git commands

git commit
- commits any staged files to current branch
- -m "commit message"

## Branches
git branch
- used to modify branches
- no modifier: lists local branches
- -r: list remote branches
- -a: list all branches (including remote)
- branch \<branch-name\>: creates a branch without switching to it
- branch \<new-branch-name\>: renames current branch
- branch \<old-name\>\<new name\>: renames specific branch
- -d \<branch-name\>: deletes branch

git checkout / git switch
- better to use git switch for safety
- switches to branch

git merge
- combines changes from another branch to current branch (while maintaining branch history)

git rebase
- combines changes from another branch to current branch (by taking entire commit history and placing at the start of branch merged to)

## Status/History
git status 
- shows the status of the working tree

git log
- displays commit history

git diff
- show differences between commit histories

## Reverting
git reset
- reset HEAD and current branch to a different commit

git restore
- restore the working tree and/or staging area
- mainly used when you changed files while files have been staged previously, allowing you to reset to that staged state (or back to last commit if nothing was staged)

git revert
- revert changes from a specific commit but creating a commit for that undo


## Remote Repositories
git clone
- clone a remote repository into a new directory

git pull
- pull changes from remote

git push
- push changes to remote

git fetch
- fetch changes from remote without merging

git remote
- manage remote repositories
- common use: list, add, remove remotes