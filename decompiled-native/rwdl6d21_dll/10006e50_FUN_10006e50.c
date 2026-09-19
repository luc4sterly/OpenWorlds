// 10006e50 FUN_10006e50 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10006e50(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  byte local_10c;
  double local_100 [32];
  
  DAT_1007c1d0 = 0;
  DAT_1007c0d0 = 0;
  local_100[0] = (double)_DAT_1007923c;
  iVar1 = 1;
  do {
    iVar3 = iVar1 + 1;
    FUN_1005ff92(param_1);
    lVar5 = __ftol();
    (&DAT_1007c1d0)[iVar1] = (char)lVar5;
    FUN_1005ff92(extraout_ECX);
    lVar5 = __ftol();
    (&DAT_1007c0d0)[iVar1] = (char)lVar5;
    param_1 = extraout_ECX_00;
    iVar1 = iVar3;
  } while (iVar3 < 0x100);
  iVar3 = 0;
  iVar1 = 0;
  do {
    local_10c = (byte)iVar1;
    if ((*(uint *)(&DAT_100791e8 + (local_10c >> 3 & 0xfffffffc)) & 1 << (local_10c & 0x1f)) != 0) {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          uVar2 = (uint)*(byte *)((int)local_100 + iVar4);
          if ((&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bec0 + uVar2)] ==
              (&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bec0 + iVar1)]) {
            if (((&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bfc0 + uVar2)] ==
                 (&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bfc0 + iVar1)]) &&
               ((&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bdb0 + uVar2)] ==
                (&DAT_1007c1d0)[*(byte *)((int)&DAT_1007bdb0 + iVar1)])) break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
      }
      if (iVar4 == iVar3) {
        *(byte *)((int)local_100 + iVar3) = local_10c;
        iVar3 = iVar3 + 1;
      }
    }
    iVar1 = iVar1 + 1;
    if (0xff < iVar1) {
      FUN_1000b5d0(iVar3,(int)local_100);
      return;
    }
  } while( true );
}


