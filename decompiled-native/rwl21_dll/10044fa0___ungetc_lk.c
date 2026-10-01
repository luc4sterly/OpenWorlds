// 10044fa0 __ungetc_lk [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __ungetc_lk
   
   Library: Visual Studio 1998 Release */

uint __cdecl __ungetc_lk(uint param_1,FILE *param_2)

{
  char *pcVar1;
  uint uVar2;
  
  if (param_1 != 0xffffffff) {
    uVar2 = param_2->_flag;
    if (((uVar2 & 1) != 0) || (((uVar2 & 0x80) != 0 && ((uVar2 & 2) == 0)))) {
      if (param_2->_base == (char *)0x0) {
        __getbuf(param_2);
      }
      if (param_2->_base == param_2->_ptr) {
        if (param_2->_cnt != 0) {
          return 0xffffffff;
        }
        param_2->_ptr = param_2->_ptr + 1;
      }
      pcVar1 = param_2->_ptr;
      if ((param_2->_flag & 0x40) == 0) {
        param_2->_ptr = pcVar1 + -1;
        pcVar1[-1] = (char)param_1;
      }
      else {
        param_2->_ptr = pcVar1 + -1;
        if (pcVar1[-1] != (char)param_1) {
          param_2->_ptr = pcVar1;
          return 0xffffffff;
        }
      }
      param_2->_cnt = param_2->_cnt + 1;
      uVar2 = param_2->_flag & 0xffffffef;
      param_2->_flag = uVar2;
      param_2->_flag = uVar2 | 1;
      return param_1 & 0xff;
    }
  }
  return 0xffffffff;
}


