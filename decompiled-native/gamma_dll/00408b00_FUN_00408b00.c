// 00408b00 FUN_00408b00 [Global]
// programa: gamma.dll

int * __thiscall FUN_00408b00(void *this,uint param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  
  FUN_00408b80(this,param_1,'\0');
  puVar1 = *(undefined1 **)(*(int *)this + 0xc);
  for (; param_1 != 0; param_1 = param_1 - 1) {
    *puVar1 = param_2;
    puVar1 = puVar1 + 1;
  }
  return this;
}


