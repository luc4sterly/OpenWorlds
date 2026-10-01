// 10044b90 _fgetc [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _fgetc
   
   Library: Visual Studio 1998 Release */

int __cdecl _fgetc(FILE *_File)

{
  int iVar1;
  uint uVar2;
  
  __lock_file(_File);
  iVar1 = _File->_cnt + -1;
  _File->_cnt = iVar1;
  if (iVar1 < 0) {
    uVar2 = __filbuf(_File);
  }
  else {
    uVar2 = (uint)(byte)*_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  __unlock_file(_File);
  return uVar2;
}


