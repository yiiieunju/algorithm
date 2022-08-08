

new_id='=.='


i=0
while i < len(new_id):
    if new_id[i].isalpha() or new_id[i].isdigit() or new_id[i] in ['-','_','.']:
        i+=1
        continue
    add =  ( '' if i == len(new_id)-1  else new_id[i+1:])
    new_id = new_id[:i] + add
    print(new_id)
    
