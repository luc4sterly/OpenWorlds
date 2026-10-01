// 0042bf40 FUN_0042bf40 [Global]
// program: gamma.dll

int * __thiscall FUN_0042bf40(void *this,int *param_1,void *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  puVar2 = (undefined4 *)((int)this + 4);
  puVar1 = *(undefined4 **)((int)this + 4);
  while (puVar1 != (undefined4 *)0x0) {
    bVar3 = FUN_004274e0(puVar1 + 3,(int)param_2);
    if (CONCAT31(extraout_var,bVar3) == 0) {
      puVar2 = puVar1;
      puVar1 = (undefined4 *)*puVar1;
    }
    else {
      puVar1 = (undefined4 *)puVar1[1];
    }
  }
  if ((puVar2 != (undefined4 *)((int)this + 4)) &&
     (bVar3 = FUN_004274e0(param_2,(int)(puVar2 + 3)), CONCAT31(extraout_var_00,bVar3) == 0)) {
    *param_1 = (int)puVar2;
    return param_1;
  }
  *param_1 = (int)this + 4;
  return param_1;
}


