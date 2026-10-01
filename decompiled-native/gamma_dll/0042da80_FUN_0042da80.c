// 0042da80 FUN_0042da80 [Global]
// program: gamma.dll

void __fastcall FUN_0042da80(undefined4 param_1,undefined4 param_2,int *param_3,void *param_4)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  uint *puVar4;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  int extraout_ECX;
  undefined1 local_1590 [264];
  int local_1488;
  undefined **local_1484;
  char local_1480 [255];
  undefined1 local_1381;
  undefined1 local_1380 [264];
  undefined **local_1278;
  char acStackY_1274 [256];
  undefined1 local_1174 [264];
  undefined1 local_106c [264];
  undefined **local_f64 [65];
  undefined **local_e60 [65];
  undefined **local_d5c;
  char local_d58 [256];
  undefined **local_c58 [65];
  undefined **local_b54 [65];
  undefined **local_a50 [65];
  undefined **local_94c;
  char acStackY_948 [256];
  undefined **local_848 [65];
  undefined **local_744;
  char acStackY_740 [256];
  undefined **local_640 [65];
  undefined **local_53c;
  char acStackY_538 [256];
  undefined **local_438 [65];
  undefined **local_334;
  char acStackY_330 [256];
  undefined **local_230 [65];
  undefined **local_12c;
  char acStackY_128 [264];
  undefined4 uStackY_20;
  
  FUN_004574c0(param_1,param_2);
  uVar3 = (**(code **)(*param_3 + 0x14))();
  *(undefined4 *)(extraout_ECX + 0xf0) = uVar3;
  if (*(int *)(extraout_ECX + 0xf0) != 0x10a) {
    uStackY_20 = 0x42dac9;
    FUN_0042c6a0(local_1590,param_3[3],*(int *)(extraout_ECX + 0xf0));
    uStackY_20 = 0x42dad4;
    FUN_00451670();
  }
  FUN_00427410(local_f64,&DAT_0049eeb8,0xff);
  FUN_00427410(local_e60,&DAT_004748f8,0xff);
  bVar2 = FUN_00427480(local_f64,(int)local_e60);
  local_f64[0] = &PTR_LAB_00471ff8;
  local_e60[0] = &PTR_LAB_00471ff8;
  if (CONCAT31(extraout_var,bVar2) != 0) {
    FUN_00427410(&local_d5c,s_cy_was_handled_specially_004749c8,0xff);
    local_1488 = param_3[3];
    local_1484 = &PTR_LAB_00471ff8;
    uStackY_20 = 0x42db7e;
    FUN_0044d6d0(local_1480,local_d58,0xff);
    local_1381 = 0;
    uStackY_20 = 0x42db98;
    FUN_00451670();
    local_d5c = &PTR_LAB_00471ff8;
  }
  FUN_00427410(local_c58,&DAT_004748f0,0xff);
  puVar4 = FUN_0042e0e0(param_4,local_c58);
  uStackY_20 = 0x42dbe4;
  FUN_0044d6d0((char *)(puVar4 + 0x42),&DAT_0049eeb8,0xff);
  *(undefined1 *)((int)puVar4 + 0x207) = 0;
  local_c58[0] = &PTR_LAB_00471ff8;
  uVar3 = (**(code **)(*param_3 + 0x14))();
  *(undefined4 *)(extraout_ECX + 0xf0) = uVar3;
  while (iVar1 = *(int *)(extraout_ECX + 0xf0), iVar1 != 0x104) {
    if (iVar1 != 0x10a) {
      uStackY_20 = 0x42dc9f;
      FUN_0042c6a0(local_1380,param_3[3],iVar1);
      uStackY_20 = 0x42dcaa;
      FUN_00451670();
    }
    FUN_00427410(&local_1278,&DAT_0049eeb8,0xff);
    uVar3 = (**(code **)(*param_3 + 0x14))();
    *(undefined4 *)(extraout_ECX + 0xf0) = uVar3;
    if (*(int *)(extraout_ECX + 0xf0) != 0x101) {
      uStackY_20 = 0x42dcf6;
      FUN_0042c6a0(local_1174,param_3[3],*(int *)(extraout_ECX + 0xf0));
      uStackY_20 = 0x42dd01;
      FUN_00451670();
    }
    uVar3 = (**(code **)(*param_3 + 0x14))();
    *(undefined4 *)(extraout_ECX + 0xf0) = uVar3;
    if (*(int *)(extraout_ECX + 0xf0) != 0x10a) {
      uStackY_20 = 0x42dd38;
      FUN_0042c6a0(local_106c,param_3[3],*(int *)(extraout_ECX + 0xf0));
      uStackY_20 = 0x42dd43;
      FUN_00451670();
    }
    FUN_00427410(local_b54,s_geometry_004748fc,0xff);
    bVar2 = FUN_00427480(&local_1278,(int)local_b54);
    local_b54[0] = &PTR_LAB_00471ff8;
    if (CONCAT31(extraout_var_00,bVar2) == 0) {
      FUN_00427410(local_848,&DAT_004749e4,0xff);
      bVar2 = FUN_00427480(&local_1278,(int)local_848);
      local_848[0] = &PTR_LAB_00471ff8;
      if (CONCAT31(extraout_var_01,bVar2) == 0) {
        FUN_00427410(local_640,&DAT_004749ec,0xff);
        bVar2 = FUN_00427480(&local_1278,(int)local_640);
        local_640[0] = &PTR_LAB_00471ff8;
        if (CONCAT31(extraout_var_02,bVar2) == 0) {
          FUN_00427410(local_438,s_endwait_004749f4,0xff);
          bVar2 = FUN_00427480(&local_1278,(int)local_438);
          local_438[0] = &PTR_LAB_00471ff8;
          if (CONCAT31(extraout_var_03,bVar2) == 0) {
            FUN_00427410(local_230,&DAT_004749fc,0xff);
            bVar2 = FUN_00427480(&local_1278,(int)local_230);
            local_230[0] = &PTR_LAB_00471ff8;
            if (CONCAT31(extraout_var_04,bVar2) != 0) {
              iVar1 = *(int *)((int)param_4 + 0x30);
              uStackY_20 = 0x42e03e;
              FUN_0044d6d0((char *)(iVar1 + 4),acStackY_1274,0xff);
              *(undefined1 *)(iVar1 + 0x103) = 0;
              FUN_00427410(&local_12c,&DAT_0049eeb8,0xff);
              iVar1 = *(int *)((int)param_4 + 0x3c);
              uStackY_20 = 0x42e074;
              FUN_0044d6d0((char *)(iVar1 + 4),acStackY_128,0xff);
              *(undefined1 *)(iVar1 + 0x103) = 0;
              local_12c = &PTR_LAB_00471ff8;
            }
          }
          else {
            iVar1 = *(int *)((int)param_4 + 0x18);
            uStackY_20 = 0x42df94;
            FUN_0044d6d0((char *)(iVar1 + 0x20c),acStackY_1274,0xff);
            *(undefined1 *)(iVar1 + 0x30b) = 0;
            FUN_00427410(&local_334,&DAT_0049eeb8,0xff);
            iVar1 = *(int *)((int)param_4 + 0x24);
            uStackY_20 = 0x42dfd0;
            FUN_0044d6d0((char *)(iVar1 + 0x20c),acStackY_330,0xff);
            *(undefined1 *)(iVar1 + 0x30b) = 0;
            local_334 = &PTR_LAB_00471ff8;
          }
        }
        else {
          iVar1 = *(int *)((int)param_4 + 0x18);
          uStackY_20 = 0x42dee4;
          FUN_0044d6d0((char *)(iVar1 + 0x108),acStackY_1274,0xff);
          *(undefined1 *)(iVar1 + 0x207) = 0;
          FUN_00427410(&local_53c,&DAT_0049eeb8,0xff);
          iVar1 = *(int *)((int)param_4 + 0x24);
          uStackY_20 = 0x42df20;
          FUN_0044d6d0((char *)(iVar1 + 0x108),acStackY_538,0xff);
          *(undefined1 *)(iVar1 + 0x207) = 0;
          local_53c = &PTR_LAB_00471ff8;
        }
      }
      else {
        iVar1 = *(int *)((int)param_4 + 0x18);
        uStackY_20 = 0x42de3f;
        FUN_0044d6d0((char *)(iVar1 + 4),acStackY_1274,0xff);
        *(undefined1 *)(iVar1 + 0x103) = 0;
        FUN_00427410(&local_744,&DAT_0049eeb8,0xff);
        iVar1 = *(int *)((int)param_4 + 0x24);
        uStackY_20 = 0x42de75;
        FUN_0044d6d0((char *)(iVar1 + 4),acStackY_740,0xff);
        *(undefined1 *)(iVar1 + 0x103) = 0;
        local_744 = &PTR_LAB_00471ff8;
      }
    }
    else {
      FUN_00427410(local_a50,s_geometry_004748fc,0xff);
      FUN_00427410(&local_94c,&DAT_0049eeb8,0xff);
      puVar4 = FUN_0042e0e0(param_4,local_a50);
      uStackY_20 = 0x42ddd0;
      FUN_0044d6d0((char *)(puVar4 + 0x42),acStackY_948,0xff);
      *(undefined1 *)((int)puVar4 + 0x207) = 0;
      local_a50[0] = &PTR_LAB_00471ff8;
      local_94c = &PTR_LAB_00471ff8;
    }
    local_1278 = &PTR_LAB_00471ff8;
    uVar3 = (**(code **)(*param_3 + 0x14))();
    *(undefined4 *)(extraout_ECX + 0xf0) = uVar3;
  }
  return;
}


