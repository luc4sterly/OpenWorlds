// 100451d0 __fseek_lk [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __fseek_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __fseek_lk(FILE *param_1,long param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  
  if (((param_1->_flag & 0x83U) != 0) && (((param_3 == 0 || (param_3 == 1)) || (param_3 == 2)))) {
    param_1->_flag = param_1->_flag & 0xffffffef;
    if (param_3 == 1) {
      param_3 = 0;
      iVar2 = __ftell_lk(&param_1->_ptr);
      param_2 = param_2 + iVar2;
    }
    __flush(param_1);
    uVar1 = param_1->_flag;
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1->_bufsiz = 0x200;
      }
    }
    else {
      param_1->_flag = uVar1 & 0xfffffffc;
    }
    lVar3 = __lseek(param_1->_file,param_2,param_3);
    return -(uint)(lVar3 == -1);
  }
  piVar4 = FUN_100490e0();
  *piVar4 = 0x16;
  return -1;
}


