

cubestring = 'DUUBULDBFRBFRRULLLBRDFFFBLURDBFDFDRFRULBLUFDURRBLBDUDL'  

import solver as sv
a = sv.solve(cubestring, 20, 2)  # solve with a maximum of 20 moves and a timeout of 2 seconds for example
print(a)
a = sv.solve(cubestring, 18, 5)  # solve with a maximum of 18 moves and a timeout of 5 seconds for example
print(a)




