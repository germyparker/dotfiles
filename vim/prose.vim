
set wrap

sy region quote  start=+\"+ end=+\"+
"sy region brack  start="\[" end="\]"
sy region quote  start="“" end="”"
hi quote ctermfg=blue guifg=blue
"hi brack ctermfg=red guifg=red

sy spell toplevel

sy region par1 matchgroup=par1 start=/(/ end=/)/ contains=par2
sy region par2 matchgroup=par2 start=/(/ end=/)/ contains=par3 contained
sy region par3 matchgroup=par3 start=/(/ end=/)/ contains=par1 contained
hi par1 ctermfg=green guifg=green
hi par2 ctermfg=darkgreen guifg=darkgreen
hi par3 ctermfg=red guifg=red
