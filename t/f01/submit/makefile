pdf:
	-python /home/student/.alex/alexrunner.py replaceemail
	pdflatex --shell-escape main.tex
	pdflatex --shell-escape main.tex
	xdg-open main.pdf

view:
	xdg-open main.pdf

v:
	xdg-open main.pdf

clean:
	rm -rf main.aux main.idx main.log main.out makefile.old main.py main.py.err main.py.out latex.py __pycache__

c:
	rm -rf main.aux main.idx main.log main.out makefile.old main.py main.py.err main.py.out latex.py __pycache__
    
s:
	rm -f main.aux main.idx main.log main.out makefile.old main.py main.py.err main.py.out latex.py
	rm -rf submit; rm -f submit.tar.gz; mkdir submit; rsync -av . submit --exclude submit; tar -cvf submit.tar submit; gzip submit.tar || true
	@echo ""
	@echo "done ... submit.tar.gz is created:"
	@ls -la submit.tar.gz
	@echo ""

a:
	cp -r ../questions/* .
