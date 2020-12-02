import PeakSegDiskInterface


def FPOP_files(coverage, segments, loss, penalty, db):
    return PeakSegDiskInterface.interface(coverage.name, segments.name, loss.name, penalty, db.name)

