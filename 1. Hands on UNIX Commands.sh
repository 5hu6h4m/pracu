#!/bin/bash

echo "Creating a file, enter the name for new file:"
read FILE
touch $FILE
echo "File created: $FILE"

echo "Writing data into file..."
echo "Name:"
read name
echo "Name: $name" > $FILE

echo ""
echo "Reading file contents:"
cat $FILE

echo ""
echo "Appending new data..."
echo "class: Second Year" >> $FILE

echo "Updated file contents:"
cat $FILE

echo ""
echo "Deleting file..."
rm $FILE
echo "File deleted."

echo "Program completed."
