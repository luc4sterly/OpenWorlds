// 00407b9d FUN_00407b9d [Global]
// programa: sfmain.exe

void __fastcall
FUN_00407b9d(short *param_1,short *param_2,int param_3,void *param_4,undefined4 param_5,
            short *param_6)

{
  int in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  short **local_15c [80];
  short ***local_1c;
  short *local_18;
  short *local_14;
  short ***local_10;
  
  psVar5 = (short *)(in_EAX + 0xf0);
  local_18 = param_1;
  FUN_00403d7d(param_1,param_2);
  FUN_00404b0c(extraout_ECX);
  FUN_004032fc(extraout_ECX_00);
  local_10 = local_15c;
  local_1c = (short ***)&local_1c;
  local_14 = psVar5;
  do {
    psVar3 = local_18;
    local_18 = local_18 + 1;
    FUN_00405377((undefined2 *)((int)&DAT_004381a4 + 2),(short *)local_10,local_14,psVar3,param_3);
    FUN_00403cb6(param_4,param_6);
    iVar1 = 0;
    psVar3 = psVar5;
    psVar4 = local_14;
    do {
      iVar2 = (int)*psVar4 + (*(int *)((int)&DAT_004381a4 + iVar1 * 2) >> 0x10);
      if (0xffff < iVar2 + 0x8000U) {
        if (iVar2 < 1) {
          iVar2 = -0x8000;
        }
        else {
          iVar2 = 0x7fff;
        }
      }
      psVar4 = psVar4 + 1;
      iVar1 = iVar1 + 1;
      *psVar3 = (short)iVar2;
      psVar3 = psVar3 + 1;
    } while (iVar1 < 0x28);
    psVar5 = psVar5 + 0x28;
    local_14 = local_14 + 0x28;
    local_10 = local_10 + 0x14;
    param_6 = param_6 + 0xd;
    param_3 = param_3 + 2;
    param_4 = (void *)((int)param_4 + 2);
  } while (local_10 != local_1c);
  FUN_004080a4(param_6,(undefined1 *)(in_EAX + 0x140));
  return;
}


