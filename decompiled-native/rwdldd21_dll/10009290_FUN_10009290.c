// 10009290 FUN_10009290 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10009290(undefined4 *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  ATOM AVar3;
  int iVar4;
  WNDPROC pWVar5;
  HWND pHVar6;
  bool bVar7;
  int iVar8;
  
  iVar4 = FUN_10026120();
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = FUN_10029900();
  if (iVar4 == 0) {
    return 0;
  }
  if (0 < param_3) {
    FUN_10009620(param_3,param_4);
  }
  if (DAT_100360a0 == 0) {
    _DAT_100360a4 = *(undefined4 *)(DAT_10036064 + 8 + DAT_10036060 * 0x28);
    _DAT_10036098 = 4;
  }
  else {
    if ((DAT_100360a0 != 0x10) && (DAT_100360a0 != 0x20)) {
      return 0;
    }
    DAT_100360a8 = DAT_100360a0;
  }
  iVar4 = _DAT_1003404c;
  if (DAT_100360ac != 0) {
    iVar4 = _DAT_10034058;
  }
  FUN_100237d0(iVar4);
  DAT_100360a8 = 0x10;
  iVar8 = 0x10;
  pWVar5 = (WNDPROC)GetSystemMetrics(0x11);
  iVar4 = GetSystemMetrics(0x10);
  iVar4 = FUN_10024c20(param_1,iVar4,pWVar5,iVar8);
  if (iVar4 != 0) {
    uVar2 = *(undefined4 *)(DAT_10036064 + 0x14 + DAT_10036060 * 0x28);
    iVar4 = DirectDrawCreate();
    if (iVar4 != 0) {
      return 0;
    }
    DAT_10038b68 = uVar2;
    iVar4 = (**(code **)*DAT_10036030)(DAT_10036030,&DAT_10034110);
    if (iVar4 != 0) {
      if (DAT_10036030 != (int *)0x0) {
        (**(code **)(*DAT_10036030 + 8))(DAT_10036030);
        DAT_10036030 = (int *)0x0;
      }
      return 0;
    }
    bVar7 = false;
    if ((DAT_10036054 == (HWND)0x0) && (DAT_10036050 == (HWND)0x0)) {
      AVar3 = RegisterClassA((WNDCLASSA *)&stack0xffffffc0);
      if (AVar3 != 0) {
        DAT_10036050 = CreateWindowExA(0,s_RWD3DDRV_10036294,s_RWD3DWND_10036288,0xcf0000,0,0,100,
                                       100,(HWND)0x0,(HMENU)0x0,DAT_10038acc,(LPVOID)0x0);
        bVar7 = DAT_10036050 != (HWND)0x0;
      }
      if (!bVar7) {
        if (DAT_10036034 != (int *)0x0) {
          (**(code **)(*DAT_10036034 + 8))(DAT_10036034);
          DAT_10036034 = (int *)0x0;
        }
        if (DAT_10036030 != (int *)0x0) {
          (**(code **)(*DAT_10036030 + 8))(DAT_10036030);
          DAT_10036030 = (int *)0x0;
        }
        return 0;
      }
    }
    puVar1 = (undefined4 *)(DAT_10036064 + DAT_10036060 * 0x28);
    if ((*(uint *)(DAT_10036064 + 0x10 + DAT_10036060 * 0x28) & 2) == 0) {
      iVar4 = (**(code **)(*DAT_10036030 + 0x54))(DAT_10036030,*puVar1,puVar1[1],puVar1[2]);
      if (iVar4 != 0) {
        (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8);
        if (DAT_10036034 != (int *)0x0) {
          (**(code **)(*DAT_10036034 + 8))(DAT_10036034);
          DAT_10036034 = (int *)0x0;
        }
        if (DAT_10036030 != (int *)0x0) {
          (**(code **)(*DAT_10036030 + 8))(DAT_10036030);
          DAT_10036030 = (int *)0x0;
        }
        return 0;
      }
      pHVar6 = DAT_10036054;
      if (DAT_10036054 == (HWND)0x0) {
        pHVar6 = DAT_10036050;
      }
      (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,pHVar6,0x11);
      iVar4 = FUN_10008930(0x11);
      if (iVar4 == 0) {
        (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8);
        if (DAT_10036034 != (int *)0x0) {
          (**(code **)(*DAT_10036034 + 8))(DAT_10036034);
          DAT_10036034 = (int *)0x0;
        }
        if (DAT_10036030 != (int *)0x0) {
          (**(code **)(*DAT_10036030 + 8))(DAT_10036030);
          DAT_10036030 = (int *)0x0;
        }
        return 0;
      }
    }
    else {
      (**(code **)(*DAT_10036030 + 0x50))(DAT_10036030,0,8);
      iVar4 = FUN_10008930(8);
      if (iVar4 == 0) {
        if (DAT_10036034 != (int *)0x0) {
          (**(code **)(*DAT_10036034 + 8))(DAT_10036034);
          DAT_10036034 = (int *)0x0;
        }
        if (DAT_10036030 != (int *)0x0) {
          (**(code **)(*DAT_10036030 + 8))(DAT_10036030);
          DAT_10036030 = (int *)0x0;
        }
        return 0;
      }
    }
    return 1;
  }
  return 0;
}


