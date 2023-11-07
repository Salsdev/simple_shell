#!/bin/bash

#This automate the creation and maintenance
# of the AUTHORS file based on Git commit history



# Append all authors to the AUTHORS file
git log --format='%aN <%aE>' >> AUTHORS

# Sort and remove duplicates, then overwrite the
# AUTHORS file with the deduplicated list
sort -u AUTHORS -o AUTHORS

#Comfimation
echo "AUTHORS file has been updated."



# Give it execute permissions: "chmod +x generate-authors.sh"
# Execute it: "./generate-authors.sh"
