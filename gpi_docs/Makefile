gpi_build-pdf:
	latexmk -pdf -output-directory=_build gpia_doc.tex
	latexmk -pdf -output-directory=_build gpib_doc.tex
	latexmk -pdf -output-directory=_build gpic_doc.tex
	latexmk -pdf -output-directory=_build gpif_doc.tex
	latexmk -pdf -output-directory=_build gpiq_doc.tex

gpi_clean:
	rm -rfv ./*/*.aux
	rm -rfv ./*/*.fdb_latexmk
	rm -rfv ./*/*.fls
	rm -rfv ./*/*.log
	rm -rfv ./*/*.out
	rm -rfv ./*/*.pdf
	rm -rfv ./*/*.synctex.gz
	rm -rfv ./*/*.toc
