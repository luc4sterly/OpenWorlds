// 004336a0 FUN_004336a0 [Global]
// programa: gamma.dll

void * __thiscall FUN_004336a0(void *this,void *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 local_34 [5];
  undefined4 local_20 [5];
  
  piVar1 = *(int **)this;
  if (piVar1 == (int *)0x0) {
    FUN_00428f10(local_20);
    puVar2 = local_20;
  }
  else {
    (**(code **)(*piVar1 + 0xc))(local_34);
    puVar2 = local_34;
  }
  FUN_00428df0(param_1,(int)puVar2);
  if (piVar1 == (int *)0x0) {
    FUN_00428e50(local_20);
  }
  else {
    FUN_00428e50(local_34);
  }
  return param_1;
}


