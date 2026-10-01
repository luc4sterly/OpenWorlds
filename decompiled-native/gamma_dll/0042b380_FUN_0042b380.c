// 0042b380 FUN_0042b380 [Global]
// program: gamma.dll

int * __thiscall FUN_0042b380(void *this,int *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)((int)this + 4);
  puVar2 = (undefined4 *)((int)this + 4);
  while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {
    if ((int)puVar1[3] < *param_2) {
      puVar3 = (undefined4 *)puVar1[1];
    }
    else {
      puVar3 = (undefined4 *)*puVar1;
      puVar2 = puVar1;
    }
  }
  if ((puVar2 != (undefined4 *)((int)this + 4)) && ((int)puVar2[3] <= *param_2)) {
    *param_1 = (int)puVar2;
    return param_1;
  }
  *param_1 = (int)this + 4;
  return param_1;
}


