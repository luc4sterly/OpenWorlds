// 100454f0 _fputc [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _fputc
   
   Library: Visual Studio 1998 Release */

int __cdecl _fputc(int _Ch,FILE *_File)

{
  int iVar1;
  uint uVar2;
  
  __lock_file(_File);
  iVar1 = _File->_cnt + -1;
  _File->_cnt = iVar1;
  if (iVar1 < 0) {
    uVar2 = __flsbuf(_Ch,_File);
  }
  else {
    *_File->_ptr = (char)_Ch;
    uVar2 = (uint)(byte)*_File->_ptr;
    _File->_ptr = _File->_ptr + 1;
  }
  __unlock_file(_File);
  return uVar2;
}


