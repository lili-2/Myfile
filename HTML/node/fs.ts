import * as fs from 'fs'

const tree = {}

const fsPath = '../../HTML/practive'

const myfs = (fsPath: any,tree :Object | any) => {
  const list = fs.readdirSync(fsPath)
  list.forEach((i:any,index:number) => {
      const statu = fs.statSync(`${fsPath}/${i}`)
      if(statu.isDirectory()){
          tree[i] = {}
          tree[i] = myfs(`${fsPath}/${i}`,tree[i]);
      }else{
          tree[index] = i
      }
  })
    return tree;
}
console.log('hello')

console.log(myfs(fsPath,tree))
console.log(myfs(fsPath,tree).css)

