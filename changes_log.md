# driver.py

## class Client()

### def update()
'''{python}
if self.reorder: 
	# Reorder data before update -yaml-reorder{segments:n1,groups:n2,inputs:n3}
	u = np.hstack([x[i] for i in range(self.reorder['segments'])
		    for x in np.split(u.reshape(-1,self.reorder['groups']),
				      self.reorder['inputs'])])
'''

insert on .yaml
reorder:
  segments: 7
  groups: 3
  inputs: 2
