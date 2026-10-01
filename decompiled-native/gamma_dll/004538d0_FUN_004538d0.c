// 004538d0 FUN_004538d0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004538d0(void *this,int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 auStack_48 [4];
  undefined **local_44;
  undefined4 local_40 [3];
  undefined ***local_34;
  undefined4 *local_30;
  undefined1 *local_18;
  undefined4 local_14;
  
  *(undefined4 *)this = 0;
  uVar1 = *(uint *)*param_1;
  if (uVar1 < param_2) {
    local_34 = &local_44;
    local_44 = &PTR_FUN_0046db74;
    local_30 = local_40;
    iVar4 = FUN_0044d690(s_string_copy_constructor__pos_>_s_00482078);
    iVar4 = FUN_00450b60(iVar4 + 1);
    FUN_00403d80(local_30,iVar4);
    FUN_0044d6b0((char *)*local_30,s_string_copy_constructor__pos_>_s_00482078);
    local_44 = &PTR_LAB_0046db54;
    FUN_00451670();
  }
  uVar6 = uVar1 - param_2;
  if (param_3 < uVar1 - param_2) {
    uVar6 = param_3;
  }
  if (uVar6 == uVar1) {
    puVar2 = (uint *)*param_1;
    FUN_00406470(&local_14,puVar2 + 4);
    bVar3 = FUN_004065c0((int)puVar2);
    if (bVar3) {
      puVar2[2] = puVar2[2] + 1;
      FUN_00404f40(&local_14);
      puVar5 = puVar2;
    }
    else {
      puVar5 = (uint *)FUN_00406450(1);
      local_18 = auStack_48;
      FUN_00406530(puVar5,puVar2);
      FUN_00404f40(&local_14);
    }
    *(uint **)this = puVar5;
  }
  else {
    FUN_00424350(this,(undefined4 *)(*(int *)(*param_1 + 0xc) + param_2),
                 *(int *)(*param_1 + 0xc) + param_2 + uVar6);
  }
  return this;
}


