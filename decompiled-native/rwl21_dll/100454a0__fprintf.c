// 100454a0 _fprintf [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _fprintf
   
   Library: Visual Studio 1998 Release */

int __cdecl _fprintf(FILE *_File,char *_Format,...)

{
  int _Flag;
  int iVar1;
  
  __lock_file(_File);
  _Flag = __stbuf(_File);
  iVar1 = __output(_File,(byte *)_Format,(undefined4 *)&stack0x0000000c);
  __ftbuf(_Flag,_File);
  __unlock_file(_File);
  return iVar1;
}


