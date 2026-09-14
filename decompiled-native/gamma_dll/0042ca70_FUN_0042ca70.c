// 0042ca70 FUN_0042ca70 [Global]
// programa: gamma.dll

void __fastcall FUN_0042ca70(void *param_1)

{
  uint *puVar1;
  undefined4 local_46c [19];
  undefined **local_420 [65];
  undefined **local_31c;
  char local_318 [256];
  undefined **local_218 [65];
  undefined **local_114;
  char local_110 [256];
  
  FUN_0042ba20(local_46c);
  FUN_00427410(local_420,&DAT_004748f0,0xff);
  FUN_00427410(&local_31c,&DAT_004748f8,0xff);
  puVar1 = FUN_0042e0e0(local_46c,local_420);
  FUN_0044d6d0((char *)(puVar1 + 0x42),local_318,0xff);
  *(undefined1 *)((int)puVar1 + 0x207) = 0;
  local_420[0] = &PTR_LAB_00471ff8;
  local_31c = &PTR_LAB_00471ff8;
  FUN_00427410(local_218,s_geometry_004748fc,0xff);
  FUN_00427410(&local_114,s_cy_rwx_00474908,0xff);
  puVar1 = FUN_0042e0e0(local_46c,local_218);
  FUN_0044d6d0((char *)(puVar1 + 0x42),local_110,0xff);
  *(undefined1 *)((int)puVar1 + 0x207) = 0;
  local_114 = &PTR_LAB_00471ff8;
  local_218[0] = &PTR_LAB_00471ff8;
  FUN_0042e990(param_1,local_46c);
  FUN_0042bc60((int)local_46c);
  return;
}


