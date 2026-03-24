# Scheduling/Interval

- First come first serve (FCFS)
- Shortest job first (SJF)
- Priority scheduling
- Round robin scheduling
- Scheduling 和 interval 高度相關且經常交織在一起，但並不是同一套演算法
    - Interval 問題的核心在於處理一維線段上的幾何關係，像是重疊、合併、交集或涵蓋範圍。
    - 當你把「任務」對應到「時間區間」時，它就成了 Interval Scheduling。它的核心在於如何在有限的資源（例如單一會議室、有限的 CPU 核）下做出決策

## Interval

### Sweep-line Algorithm

- 我們想像有一條時間線，我們從 `t = 0` 一路往後走訪。
- 每當遇到一個會議的「起點」，我們就需要多一間會議室；每當遇到一個會議的「終點」，我們就可以釋放一間會議室。 => 最大重疊數

## Real-time scheduling

- Rate monotonic scheduling (rm)
- Earliest deadline first (EDF)

## Disk scheduling

Target: reduce seek time for disk I/O === reduce seek distance

- FCFS (First come first serve)
- SSTF (Shortest seek time first)
- SCAN
- C-SCAN (Circular SCAN)
- LOOK and C-LOOK