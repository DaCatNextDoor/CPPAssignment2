Creator(const string& channel_name, int regNo) : channel_name(channel_name), regNo(regNo), like_dislike_ratio_total(0.0) {}

int getRegNo() const
{
    return regNo;
}

void addScore(float score, const string& video_name)
{
    videos_and_ratios.insert({ video_name, score });
}

bool updateLikeDislikeRatio()
{
    if (videos_and_ratios.empty())
    {
        throw NoScoreException("Creator has no videos.");
    }

    float totalScore = 0.0;

    for (const auto& entry : videos_and_ratios)
    {
        totalScore += entry.second;
    }

    like_dislike_ratio_total = totalScore / videos_and_ratios.size();
    return true;
}