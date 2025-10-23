from latextool_basic import *
p = Plot()

# p
p += Rect(x0=-1, y0=2, x1=0, y1=3, background='white', linewidth=0, label=r'\texttt{p}')
pbox = Rect(x0=0, y0=2, x1=1, y1=3, background='white', linewidth=0.05)
p += pbox

# q
p += Rect(x0=-1, y0=0.5, x1=0, y1=1.5, background='white', linewidth=0, label=r'\texttt{q}')
qbox = Rect(x0=0, y0=0.5, x1=1, y1=1.5, background='white', linewidth=0.05)
p += qbox

abox = Rect(x0=3, y0=2, x1=4, y1=3, background='white', linewidth=0.05,
            label=r'\texttt{0}')
p += abox

# border
p += Rect(x0=-1.25, y0=0, x1=5, y1=3.5, linewidth=0.1)

p += Line(points=[(pbox.centerx(), pbox.centery()),
                  (abox.leftx(), abox.centery())],
          startstyle='dot', linewidth=0.05,
          endstyle='->')

p += Line(points=[(qbox.centerx(), qbox.centery()),
                  (abox.leftx(), abox.centery())],
          startstyle='dot', linewidth=0.05,
          endstyle='->')

print(p)

