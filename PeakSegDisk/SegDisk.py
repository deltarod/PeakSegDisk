import PeakSegDiskInterface
import tempfile


def FPOP_files(coverage, segments, loss, penalty, db=None):
    if db is None:
        with tempfile.NamedTemporaryFile(suffix='.db') as db:
            return PeakSegDiskInterface.interface(coverage, segments, loss, penalty, db.name)
    return PeakSegDiskInterface.interface(coverage, segments, loss, penalty, db.name)


