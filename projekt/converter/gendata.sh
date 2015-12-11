function full () {
echo "converting full $1 with degree constraint $2"
./converter full $1 $(cat $1 | wc -l) $2 > dataset/myshrd/$(basename $1)_$2
}

function half () {
echo "converting half $1 with degree constraint $2"
./converter half $1 $(./sizer $1) $2 > dataset/myshrd/$(basename $1)_$2
}

for i in $(find dataset/shrd/* -name "crd*" | sort);
do
  full $i 2;
  full $i 3;
  full $i 4;
  full $i 5;
done;

for i in $(find dataset/shrd/* -name "sym*" | sort);
do
  half $i 2;
  half $i 3;
  half $i 4;
  half $i 5;
done;

for i in $(find dataset/shrd/* -name "str*" | sort);
do
  half $i 2;
  half $i 3;
  half $i 4;
  half $i 5;
done;

for i in $(find dataset/shrd/* -name "shrd*" | sort);
do
  half $i 2;
  half $i 3;
  half $i 4;
  half $i 5;
done;
