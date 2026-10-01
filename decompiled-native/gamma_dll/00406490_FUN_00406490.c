// 00406490 FUN_00406490 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00406490(void *this,undefined4 *param_1)

{
  uint *puVar1;
  bool bVar2;
  uint *puVar3;
  undefined1 auStack_30 [24];
  undefined1 *local_18;
  undefined4 local_14;
  
  *(undefined4 *)this = *param_1;
  puVar1 = (uint *)*param_1;
  FUN_00406470(&local_14,puVar1 + 4);
  bVar2 = FUN_004065c0((int)puVar1);
  if (bVar2) {
    puVar1[2] = puVar1[2] + 1;
    FUN_00404f40(&local_14);
    puVar3 = puVar1;
  }
  else {
    puVar3 = (uint *)FUN_00406450(1);
    local_18 = auStack_30;
    FUN_00406530(puVar3,puVar1);
    FUN_00404f40(&local_14);
  }
  *(uint **)this = puVar3;
  return this;
}


