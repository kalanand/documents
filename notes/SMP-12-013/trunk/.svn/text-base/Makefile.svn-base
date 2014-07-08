TARGET = ../../tmp/SMP-12-013_temp.pdf
all:	$(TARGET)

$(TARGET): $(wildcard *.tex) $(wildcard figures/*.pdf)
	../../tdr --style=pas b SMP-12-013
clean:
	../../tdr clean

final: $(wildcard *.tex) $(wildcard figures/*.pdf)
	../../tdr --nodraft --style=pas b SMP-12-013
prl: $(wildcard *.tex) $(wildcard figures/*.pdf)
	../../tdr --nodraft --style=paper,aps,twocolumn b SMP-12-013
