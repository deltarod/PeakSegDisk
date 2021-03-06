import PeakSegDisk
import tempfile
import filecmp
import os

dataPath = os.path.join('data')

def test_PeakSegDisk():
    coveragePath = os.path.join(dataPath, 'coverage.bedGraph')
    segmentsPath = os.path.join(dataPath, 'segments.bed')
    correctSegmentsPath = os.path.join(dataPath, 'correctSegments.bed')
    lossPath = os.path.join(dataPath, 'loss.tsv')
    correctLossPath = os.path.join(dataPath, 'correctLoss.tsv')

    penalty = '100000'

    correct = PeakSegDisk.FPOP_files(coveragePath, segmentsPath, lossPath, penalty)

    assert correct

    assert filecmp.cmp(segmentsPath, correctSegmentsPath)

    assert filecmp.cmp(lossPath, correctLossPath)



