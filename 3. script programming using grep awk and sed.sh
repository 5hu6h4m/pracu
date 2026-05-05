
echo "--Fruit Sales Manager--"

echo "Enter filename to store sales data:"
read x
#sales.txt

#Create File
touch $x
echo "File created: $x"

#Take user input
echo "Enter Fruit name"
read fruit

echo "Enter sales:"
read sales

#Write to file
echo "$fruit $sales" > $x

echo ""
echo "Current file content:"
cat $x

#Append default data
echo "apple 10" >> $x
echo "banana 30" >> $x
echo "kiwi 50" >> $x
echo "strawberry 20" >> $x
echo "mango 80" >> $x

echo ""
echo "Updated Data:"
cat $x

#Analysis
echo ""
echo "---Analysis---"

echo "apple sales:"
grep "apple" $x

echo ""
echo "Total Sales:"
grep "apple" $x | awk '{sum += $2} END {print sum}'

echo ""
echo "Formatted output:"
sed 's/apple/APPLE/g' $x

echo ""
echo "Sales greater than 20:"
awk '$2 > 20 {print $1, $2}' $x
