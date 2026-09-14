// 00403d80 FUN_00403d80 [Global]
// programa: gamma.dll

int * __thiscall FUN_00403d80(void *this,int param_1)

{
  uint *puVar1;
  undefined1 auStack_20 [20];
  undefined1 *local_c;
  
  local_c = auStack_20;
  *(int *)this = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  if (*(int *)this != 0) {
    puVar1 = FUN_0044e010(4);
    if (puVar1 != (uint *)0x0) {
      *puVar1 = 1;
    }
    *(uint **)((int)this + 4) = puVar1;
  }
  return this;
}


