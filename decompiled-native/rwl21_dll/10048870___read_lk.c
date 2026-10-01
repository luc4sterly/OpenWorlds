// 10048870 __read_lk [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __read_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __read_lk(uint param_1,char *param_2,DWORD param_3)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  BOOL BVar5;
  DWORD DVar6;
  int *piVar7;
  ulong *puVar8;
  byte bVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char local_d;
  DWORD local_c;
  DWORD local_8;
  char *local_4;
  
  local_c = 0;
  if (param_3 != 0) {
    piVar7 = (int *)((int)&DAT_1005f6d0 + ((int)(param_1 & 0xffffffe7) >> 3));
    iVar3 = (param_1 & 0x1f) * 0x24;
    iVar4 = *piVar7 + iVar3;
    if ((*(byte *)(iVar4 + 4) & 2) == 0) {
      pcVar10 = param_2;
      if (((*(byte *)(iVar4 + 4) & 0x48) != 0) && (*(char *)(iVar4 + 5) != '\n')) {
        *param_2 = *(char *)(iVar4 + 5);
        pcVar10 = param_2 + 1;
        param_3 = param_3 - 1;
        local_c = 1;
        *(undefined1 *)(*piVar7 + 5 + iVar3) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar7 + iVar3),pcVar10,param_3,&local_8,(LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          piVar7 = FUN_100490e0();
          *piVar7 = 9;
          puVar8 = FUN_100490f0();
          *puVar8 = 5;
          return -1;
        }
        if (DVar6 != 0x6d) {
          __dosmaperr(DVar6);
          return -1;
        }
        return 0;
      }
      local_c = local_c + local_8;
      pbVar1 = (byte *)(*piVar7 + 4 + iVar3);
      bVar9 = *pbVar1;
      if ((bVar9 & 0x80) != 0) {
        if ((local_8 == 0) || (*param_2 != '\n')) {
          bVar9 = bVar9 & 0xfb;
        }
        else {
          bVar9 = bVar9 | 4;
        }
        *pbVar1 = bVar9;
        local_4 = param_2 + local_c;
        pcVar10 = param_2;
        pcVar12 = param_2;
        if (param_2 < local_4) {
          do {
            cVar2 = *pcVar10;
            if (cVar2 == '\x1a') {
              pbVar1 = (byte *)(*piVar7 + 4 + iVar3);
              bVar9 = *pbVar1;
              if ((bVar9 & 0x40) == 0) {
                *pbVar1 = bVar9 | 2;
              }
              break;
            }
            if (cVar2 == '\r') {
              if (pcVar10 < local_4 + -1) {
                pcVar11 = pcVar10 + 1;
                if (*pcVar11 == '\n') {
                  pcVar11 = pcVar10 + 2;
                  *pcVar12 = '\n';
                }
                else {
                  *pcVar12 = '\r';
                }
                goto LAB_10048a62;
              }
              pcVar11 = pcVar10 + 1;
              local_c = 0;
              BVar5 = ReadFile(*(HANDLE *)(*piVar7 + iVar3),&local_d,1,&local_8,(LPOVERLAPPED)0x0);
              if (BVar5 == 0) {
                local_c = GetLastError();
              }
              if ((local_c != 0) || (local_8 == 0)) {
LAB_10048a5f:
                *pcVar12 = '\r';
                goto LAB_10048a62;
              }
              if ((*(byte *)(*piVar7 + 4 + iVar3) & 0x48) == 0) {
                if ((pcVar12 == param_2) && (local_d == '\n')) {
                  *pcVar12 = '\n';
                  goto LAB_10048a62;
                }
                __lseek_lk(param_1,-1,1);
                if (local_d != '\n') goto LAB_10048a5f;
              }
              else {
                if (local_d == '\n') {
                  *pcVar12 = '\n';
                  goto LAB_10048a62;
                }
                *pcVar12 = '\r';
                pcVar12 = pcVar12 + 1;
                *(char *)(*piVar7 + 5 + iVar3) = local_d;
              }
            }
            else {
              pcVar11 = pcVar10 + 1;
              *pcVar12 = cVar2;
LAB_10048a62:
              pcVar12 = pcVar12 + 1;
            }
            pcVar10 = pcVar11;
          } while (pcVar11 < local_4);
        }
        local_c = (int)pcVar12 - (int)param_2;
      }
      return local_c;
    }
  }
  return 0;
}


